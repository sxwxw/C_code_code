// 导入express
const express = require('express')
const router = require('./router')

// 创建服务器
const app = express()

// 注册中间件
app.use(express.urlencoded())

// 解决跨域问题 cros中间件（CORS跨域资源共享）
const cors = require('cors')
app.use(cors())

// 挂载路由
app.use('/api', router)

// 启动服务器
app.listen(80, () => {
  console.log('启动成功 http://127.0.0.1')
})
