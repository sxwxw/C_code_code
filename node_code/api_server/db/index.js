// 导入模块
const mysql = require('mysql')

// 创建数据库连接对象
const db = mysql.createPool({
  host: '127.0.0.1',
  user: 'node',
  password: '123456',
  database: 'node'
})
// 向外共享
module.exports = db
