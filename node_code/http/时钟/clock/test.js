// 导入模块
const fs = require('fs')
const path = require('path')
const http = require('http')
// 创建服务器
const server = http.createServer()
// 绑定request事件
server.on('request', (req, res) => {
  const url = req.url
  // 将获得的url映射到本地文件
  let fpath = ''
  if (url === '/') {
    fpath = path.join(__dirname, './index.html')
  } else {
    fpath = path.join(__dirname, url)
  }
  // const fpath = path.join(__dirname, url)
  fs.readFile(fpath, 'utf-8', (err, data) => {
    if (err) {
      return res.end('404 Not Found')
    }
    res.end(data)
  })
})
// 启动服务器
server.listen(80, () => {
  console.log('服务器启动成功')
})
