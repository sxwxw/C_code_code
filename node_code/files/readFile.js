// 导入模块
const fs = require('fs')
// 调用fs.readFile读取文件 成功 err=>null 失败err=>true
fs.readFile('./data.txt', 'utf-8', function (err, data) {
  console.log(err)
  console.log(data)
})
