const path = require('path')
const fs = require('fs')
// path.join()拼接字符串
const pathStr = path.join('/a', '/b', '/c')

// ../ 会抵消前一个的路径
const pathString = path.join('/a', '../', '/c')

// 利用path.jion() 拼接路径
fs.readFile(path.join(__dirname, './data.txt'), 'utf-8', function (err, data) {
  if (err) {
    return console.log(err.message)
  }
  console.log(data)
})

// path.basename() 返回路径的文件名
const fpath = '/b/c/index.html'
const fullName = path.basename(fpath, '.html')
console.log(fullName)

// path.extname() 获取文件的拓展名
const extName = path.extname(fpath)
console.log(extName)
