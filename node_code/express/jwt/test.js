const express = require('express')
const app = express()

// 用于生成jwt 字符串
const jwt = require('jsonwebtoken')
// 将客户端发送的jwt字符串解析为json格式
const expressJWT = require('express-jwt')

// 允许跨域
const cors = require('cors')
app.use(cors())

// 解析数据
app.use(express.json())
app.use(express.urlencoded())

// 命名密钥
const secreKey = 'item@^ONE*$'

// 解析jwt字符串 unless用来指定哪些接口不需要访问权限
// 配置好了express-jwt 将会把解析的数据挂载在req.user()
app.use(expressJWT({ secret: secreKey, algorithms: ['HS256'] }).unless({ path: [/^\/api\//] }))

// 登录或注册不需要权限
app.post('/api/login', (req, res) => {
  if (req.body.username != 'admin' || req.body.password != '888888') {
    return res.send({
      status: 1,
      msg: '登录失败 '
    })
  }
  // 生成加密的token字符串 不要将隐私放到token里面
  const tokenObj = jwt.sign({ username: req.body.username }, secreKey, { expiresIn: '10s' })
  res.send({
    status: 200,
    msg: '登录成功',
    token: tokenObj
  })
})

// 发送需要权限的请求时，会使用全局注册的expressJWT中间件解析数据
app.get('/admin/getuser', (req, res) => {
  res.send({
    status: 200,
    data: req.user,
    msg: '获取信息成功'
  })
})

// jwt错误中间件
app.use((err, req, res, next) => {
  if (err.name === 'UnauthorizedError') {
    return res.send({
      status: 0,
      msg: '无效token'
    })
  }
  res.send({
    status: 500,
    msg: '未知错误'
  })
  next()
})
// 启动服务器
app.listen(80, (req, res) => {
  console.log('启动成功')
})
