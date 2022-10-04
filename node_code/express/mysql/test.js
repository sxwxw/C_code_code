// 导入模块
const mysql = require('mysql')

// 创建数据库连接关系
const db = mysql.createPool({
  host: '127.0.0.1',
  database: 'node',
  user: 'node',
  password: '123456'
})

// 测试mysql正常工作
// db.query('select 1', (err, res) => {
//   if (err) {
//     return console.log(err)
//   }
//   console.log('mysql模块正常')
// })

// 查询
// let select = 'select * from users where status=0'
// db.query(select, (err, res) => {
//   if (err) {
//     return console.log('获取失败')
//   }
//   console.log(res)
// })

// 增加
// const user = { username: 'syq', password: 123456, status: 0, delete: 1 }
// const sqlStr = 'insert into users set ?'
// db.query(sqlStr, user, (err, res) => {
//   if (err) {
//     return console.log(err.message)
//   }
//   if (res.affectedRows === 1) {
//     console.log('成功')
//   }
// })

// 更新
// const user = { id: 6, username: 'wty', password: 123456 }
// const sqlStr = 'update users set ? where id=?'
// db.query(sqlStr, [user, user.id], (err, res) => {
//   if (err) {
//     return console.log(err.message)
//   }
//   if (res.affectedRows === 1) {
//     console.log('成功')
//   }
// })

// 删除
// const sqlStr = 'delete from users where id=?'
// db.query(sqlStr, 6, (err, res) => {
//   if (err) {
//     return console.log(err.message)
//   }
//   if (res.affectedRows === 1) {
//     console.log('成功')
//   }
// })

// 标记删除
const sqlStr = 'update users set deletes=1 where id=?'
db.query(sqlStr, 9, (err, res) => {
  if (err) {
    return console.log(err.message)
  }
  if (res.affectedRows === 1) {
    console.log('成功')
  }
})
