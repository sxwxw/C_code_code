// 导入模块
const fs = require('fs')
// 调用fs.writeFile写入文件 成功 err=>null 失败err=>true
fs.writeFile('./data.txt', '你来自地狱', function (err) {
  console.log(err)
})
