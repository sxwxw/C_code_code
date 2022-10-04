const express = require('express')
const router = express.Router()

// 导入处理函数
const dataHandle = require('../controller/todoList')

// 获取数据
router.get('/allData', dataHandle.allData)

// 添加数据
router.post('/addTodo', dataHandle.addTodo)

// 删除单条数据
router.post('/deletTodo', dataHandle.deletTodo)

// 删除全部数据
router.post('/deletAllTodo', dataHandle.deletAllTodo)

module.exports = router
