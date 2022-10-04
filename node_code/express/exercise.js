// 导入模块
const express = require('express')
const qs = require('querystring')

// 创建服务器
const app = express()

// 定义中间件
const params = (req, res, next) => {
  let str = ''
  req.on('data', chunk => {
    // ''+= 将数据转换为字符串
    str += chunk
  })
  req.on('end', () => {
    // qs.parse() 将数据解析为对象
    const body = qs.parse(str)
    req.body = body
  })
  next()
}

// 注册中间件
app.use(params)

// 注册路由
app.post('/params', (req, res) => {
  res.send('post')
})

// 启动服务器
app.listen(80, () => {
  console.log('服务器启动成功')
})
