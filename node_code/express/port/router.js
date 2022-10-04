// 导入模块
const express = require('express')
const router = express.Router()

// 挂载路由
router.get('/user/list', (req, res) => {
  // req.query 获取客户端通过查询字符串发送到服务器的数据
  const query = req.query
  res.send({
    atatus: 1,
    data: query,
    message: 'GET成功'
  })
})

router.post('/user/add', (req, res) => {
  const body = req.body
  res.send({
    atatus: 1,
    data: body,
    message: 'POst成功'
  })
})

router.post('/user/del', (req, res) => {
  console.log(req.body)
  res.send('POST')
})

// 导出路由
module.exports = router
