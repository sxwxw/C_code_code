const express = require('express')
const app = express()

// 配置express-session中间件
const session = require('express-session')
app.use(
  session({
    secret: 'itheima',
    resave: 'false',
    saveUninitialized: true
  })
)

app.use(express.json())
app.use(express.urlencoded())

// 登录API
app.post('/api/logins', (req, res) => {
  if (req.body.username != 'admin' || req.body.password != '888888') {
    return res.send({
      status: 1,
      msg: '登陆失败'
    })
  }
  req.session.user = req.body
  req.session.islogin = true
  res.send({
    status: 0,
    msg: '登录失败'
  })
})

// 获取用户名
app.get('/api/username', (req, res) => {
  if (!req.session.islogin) {
    return res.send({
      status: 0,
      msg: '未登录'
    })
  }
  res.send({
    status: 0,
    data: req.session.user.username,
    msg: '登陆成功'
  })
})

// 清空session 退出登录
app.post('/api/logout', (req, res) => {
  req.session.destroy()
  res.send({
    status: 0,
    msg: '退出成功'
  })
})

// 启动服务器
app.listen(80, () => {
  console.log('启动成功 http://127.0.0.1')
})
