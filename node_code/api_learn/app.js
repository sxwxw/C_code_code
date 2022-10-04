const express = require('express')
const morgan = require('morgan')
const cors = require('cors')
const expressJWT = require('express-jwt')
const app = express() //创建服务器
const userRouter = require('./router/user')
const errorHandle = require('./middleware/error')
const config = require('../config/config.default')
// 配置常用中间件
// 日志输出
app.use(morgan('dev'))
// 解析请求体
app.use(express.json())
// 提供跨域请求
app.use(cors())
// 解析jwt字符串
// 只要配置成功jwtexpress就会把解析的出来的信息挂载在req.user
app.use(
  expressJWT({
    secret: config.jwtSecretKey
  }).unless({ path: [/^\/api\//] })
)
// 挂载路由
app.use('/api', userRouter)

// 错误中间件
app.use(errorHandle())

app.listen(8080, () => {
  console.log('server is sucess http://127.0.0.1:8080')
})
