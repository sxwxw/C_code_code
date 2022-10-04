const db = require('../db/index')
const bcryptjs = require('bcryptjs')

exports.getUserInfo = (req, res) => {
  console.log(req)
  const sql = `select username from users where id=?`
  db.query(sql, req.user.id, (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.length != 1) {
      return res.cc('获取用户失败')
    }
    res.send({
      status: 0,
      data: result[0],
      msg: '获取成功'
    })
  })
}

exports.updateUserInfo = (req, res) => {
  const updateSql = `update users set ? where id=?`
  db.query(updateSql, [req.body, req.body.id], (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.affectedRows != 1) {
      return res.cc('修改用户失败')
    }
    return res.send({
      status: 200,
      data: '修改成功'
    })
  })
}

exports.updatePwd = (req, res) => {
  const oneSql = `select * from users where id=?`
  db.query(oneSql, req.user.id, (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.length != 1) {
      return res.cc('该用户不存在')
    }
    const compareResult = bcryptjs.compareSync(req.body.oldPwd, result[0].password)
    if (!compareResult) {
      return res.cc('原密码错误')
    }
    const newPwd = bcryptjs.hashSync(req.body.newPwd, 10)
    const updatePwdSql = `update users set password=? where id=?`
    db.query(updatePwdSql, [newPwd, req.user.id], (err, result) => {
      if (err) {
        return res.cc(err)
      }
      if (result.affectedRows != 1) {
        return res.cc('修改失败')
      }
      return res.send({
        status: 200,
        msg: '修改成功'
      })
    })
  })
}

/*
全局中间件使用了express-jwt解析token以后将解析的信息挂载在属性req.user

req.body 一般用于获取post的参数

req.query 一般用于获取get的参数

req.params 一般用于获取url上的动态参数

bcryptjs 有compareSync将数据库中的密码解密 hashSync将传递的密码加密存储到数据库中

*/
