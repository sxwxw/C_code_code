// 导入模块
const fs = require('fs')
const path = require('path')
// 正则表达式
const regStyle = /<style>[\s\S]*<\/style>/
const regScript = /<script>[\s\S]*<\/script>/
// 写入文件
fs.readFile(path.join(__dirname, './index.html'), 'utf-8', function (err, data) {
  if (err) {
    return console.log(err.message)
  }
  resolveCss(data)
  resolveJs(data)
  resolveHtml(data)
})

function resolveCss(htmlStr) {
  const str = regStyle.exec(htmlStr)
  const newCss = str[0].replace('<style>', '').replace('</style>', '')
  fs.writeFile(path.join(__dirname, './clock/index.css'), newCss, function (err) {
    if (err) {
      return console.log(err.message)
    }
    console.log('写入成功')
  })
}

function resolveJs(htmlStr) {
  const str = regScript.exec(htmlStr)
  const newJs = str[0].replace('<script>', '').replace('</script>', '')
  fs.writeFile(path.join(__dirname, './clock/index.js'), newJs, function (err) {
    if (err) {
      return console.log(err.message)
    }
    console.log('写入成功')
  })
}

function resolveHtml(htmlStr) {
  const newHtml = htmlStr.replace(regStyle, '<link rel="stylesheet" href="./index.css">').replace(regScript, '<script src="./index.js"></script>')
  fs.writeFile(path.join(__dirname, './clock/index.html'), newHtml, function (err) {
    if (err) {
      return console.log(err.message)
    }
    console.log('写入成功')
  })
}
