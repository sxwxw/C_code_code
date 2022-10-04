// 导入模块
const express = require('express')
const config = require('./config')
const expressJWT = require('express-jwt')
const cors = require('cors')
const userRouter = require('./router/user')
const userinfoRouter = require('./router/userinfo')
const artecateRouter = require('./router/artcate')
const joi = require('joi')

const app = express() // 创建服务器

app.use(cors()) // 跨域问题

// res.send中间件
app.use((req, res, next) => {
  res.cc = (err, status = 1) => {
    res.send({
      status,
      message: err instanceof Error ? err.message : err
    })
  }
  next()
})

// 解析token
// 配置好了express-jwt 将会把解析的数据挂载在req.user()
app.use(
  expressJWT({
    secret: config.jwtSecretKey
  }).unless({ path: [/^\/api\//] })
)

// 表单解析数据
app.use(express.json())
app.use(express.urlencoded({ extended: false }))

// 注册路由中间件
app.use('/api', userRouter)
app.use('/user', userinfoRouter)
app.use('/article', artecateRouter)

// 错误级别中间件
app.use((err, req, res, next) => {
  if (err instanceof joi.ValidationError) {
    return res.cc(err)
  }
  if (err.name === 'UnauthorizedError') {
    return res.cc('身份认证失败')
  }
  res.cc(err)
})

// 启动服务器
app.listen(8000, (req, res) => {
  console.log('启动成功 http://127.0.0.1:8000')
})
