// 导入http模块
const http = require('http')
const path = require('path/posix')
// 创建web服务器实例
const server = http.createServer()
// 为服务器绑定reques事件
// 只要客户端接收到服务器的请求就会通过server.on调用
// 为服务器绑定request事件函数
// 使用req访问客户端相关的数据或属性
// req是请求对象 res是响应对象
// 使用res访问服务器相关的数据或属性
server.on('request', function (req, res) {
  // console.log('绑定request')
  const url = req.url
  const method = req.method
  const str = `你访问的url为${url},访问形式为${method}`
  // res.end() 服务器端向客户端相应一些内容
  // res.setHeader 设置响应头
  res.setHeader('Content-Type', 'text/html; charset=utf-8')
  res.end(str)
})
// 启动服务器
server.listen(8080, function () {
  console.log('第一个web服务器')
})
