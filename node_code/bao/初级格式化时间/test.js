// 导入第三方模块
const TIME = require('./dateFormat')
const dtStr = new Date()
const nowTime = TIME.dateFormat(dtStr)
console.log(nowTime)
