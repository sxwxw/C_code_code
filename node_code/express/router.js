// 导入模块  创建路由对象
const express = require('express')
const router = express.Router()

// 挂载路由 路由级别的中间件
router.get('/user/list', (req, res) => {
  res.send('GET')
})

router.post('/user/add', (req, res) => {
  // req.body 获取客户端请求的数据
  console.log(req.body)
  res.send('POST')
})

router.post('/user/del', (req, res) => {
  console.log(req.body)
  res.send('POST')
})

// 导出路由
module.exports = router
