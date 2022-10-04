const fs = require('fs')
fs.readFile('./原始成绩.txt', 'utf-8', function (err, data) {
  if (err) {
    return console.log('读取文件失败:' + err.message)
  } else {
    // split 利用所得参数将字符串分割成数组
    // repalce 替换字符串某串值
    // join 利用所得参数拼接字符串
    const arrOld = data.split(' ')
    const arrNew = []
    arrOld.find(item => {
      arrNew.push(item.replace('=', ':'))
    })
    const arrNow = arrNew.join('\r\n')
    fs.writeFile('./最终成绩.text', arrNow, function (err) {
      if (err) {
        return console.log('写入文件失败' + err.message)
      }
      console.log('写入文件成功')
    })
  }
})
