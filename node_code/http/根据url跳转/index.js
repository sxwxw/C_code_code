// 导入模块
const http = require('http')
const fs = require('fs')
// 创建服务器
const server = http.createServer()
// 绑定request事件
server.on('request', function (req, res) {
  const url = req.url
  let content = '<h1>404 Not found</h1>'
  if (url === '/' || url === '/index.html') {
    content = '<h1>首页</h1>'
  } else if (url === '/about.html') {
    content = '<h1>关于</h1>'
  }
  res.setHeader('Content-Type', 'text/html; charset=utf-8')
  res.end(content)
})
// 启动服务器
server.listen(8080, function () {
  console.log('服务器启动成功')
})
