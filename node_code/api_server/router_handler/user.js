const bcryptjs = require('bcryptjs')
const jwt = require('jsonwebtoken') // 用于生成jwt 字符串
const config = require('../config') // 导入全局配置文件
const db = require('../db/index')

exports.reguser = (req, res) => {
  const userInofo = req.body
  // 判断用户名重复
  const sqlStr = 'select * from users where username=?'
  db.query(sqlStr, userInofo.username, (err, results) => {
    if (err) {
      return res.cc()
    }
    if (results.length > 0) {
      return res.cc('该用户名已被注册')
    }
    // 密码加密
    userInofo.password = bcryptjs.hashSync(userInofo.password, 10)
    const sql = 'insert into users set ?'
    db.query(
      sql,
      { username: userInofo.username, password: userInofo.password },
      (err, results) => {
        if (err) {
          return res.cc()
        }
        if (results.affectedRows !== 1) {
          return res.cc('注册失败')
        }
        res.cc('注册成功')
      }
    )
  })
}

exports.login = (req, res) => {
  const userInofo = req.body
  console.log(userInofo)
  const sqlStr = 'select * from users where username=?'
  db.query(sqlStr, userInofo.username, (err, results) => {
    if (err) {
      return res.cc()
    }
    if (results.length != 1) {
      return res.cc('登陆失败')
    }
    const compareResult = bcryptjs.compareSync(userInofo.password, results[0].password)
    if (!compareResult) {
      return res.cc('登陆失败')
    }
    const user = { ...results[0], password: '', user_pic: '' }
    const tokenStr = jwt.sign(user, config.jwtSecretKey, { expiresIn: '10h' })
    res.send({
      name: userInofo.username,
      status: 200,
      msg: '登录成功',
      token: 'Bearer ' + tokenStr
    })
  })
}

/*
jwt.sign(user, config.jwtSecretKey, { expiresIn: '10h' }) 生成token

在app.js 有对应的解析token中间件 expressJWT

*/
