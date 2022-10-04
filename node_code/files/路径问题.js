// __dirname 表示当前文件所在目录
// 不使用相对路径以免出现路径动态拼接错误
const fs = require('fs')
fs.readFile(__dirname + '/data.txt', 'utf-8', function (err, data) {
  if (err) {
    return console.log('读取文件失败' + err.message)
  }
  console.log(data)
})
