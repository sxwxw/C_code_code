const db = require('../model/index')
const bcryptjs = require('bcryptjs')
const jwt = require('jsonwebtoken')
const config = require('../config/config.default')
exports.login = (req, res) => {
  let userInfo = req.body
  const loginSql = `select * from users where username=?`
  db.query(loginSql, userInfo.username, (err, result) => {
    if (err) {
      return res.send('登陆失败')
    }
    if (result.length != 1) {
      return res.send('登陆失败')
    }
    // 返回的是布尔值
    const compareResult = bcryptjs.compareSync(userInfo.password, result[0].password)
    if (!compareResult) {
      return res.cc('登陆失败')
    }
    const user = { ...result[0], password: '', user_pic: '' }
    const tokenStr = jwt.sign(user, config.jwtSecretKey, { expiresIn: '10h' })
    res.send({
      status: 200,
      msg: '登录成功',
      token: 'Bearer ' + tokenStr
    })
  })
}

exports.reguser = (req, res) => {
  let userInfo = req.body
  const reguserSql = `insert into users set ?`
  const repeatSql = `select username from users where username=?`
  db.query(repeatSql, userInfo.username, (err, result) => {
    if (err) {
      return res.send(err)
    }
    if (result.length > 0) {
      return res.send('该用户已注册')
    }
    // 进行密码加密
    userInfo.password = bcryptjs.hashSync(userInfo.password, 10)
    db.query(reguserSql, { username: userInfo.username, password: userInfo.password }, (err, result) => {
      if (result.affectedRows != 1) {
        return res.send('注册失败')
      }
      res.send('注册成功')
    })
  })
}
/*
1. 基本数据验证
2. 业务数据验证
*/
