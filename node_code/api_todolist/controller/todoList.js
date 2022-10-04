const db = require('../model')

exports.allData = (req, res) => {
  let sql = `select * from todo_list`
  db.query(sql, (err, result) => {
    let obj = {
      data: result
    }
    res.send(obj)
  })
}

exports.addTodo = (req, res) => {
  let todo = req.body
  let sql = `insert into todo_list set ?`
  db.query(sql, { content: todo.content }, (err, result) => {
    if (err) {
      return res.send(err)
    }
    if (result.affectedRows != 1) {
      return res.send('添加失败')
    }
    res.send('添加成功')
  })
}

exports.deletTodo = (req, res) => {
  let todo = req.body
  let sql1 = `delete from todo_list where id=?;alter table todo_list auto_increment=0;`
  db.query(sql1, todo.id, (err, result) => {
    if (err) {
      return res.send(err)
    }
    res.send('删除成功')
  })
}

exports.deletAllTodo = (req, res) => {
  let sql1 = `delete from todo_list`
  db.query(sql1, (err, result) => {
    if (err) {
      return res.send(err)
    }
    res.send('删除成功')
  })
}
