const express = require('express')
const router = express.Router() // 创建路由对象
const expressJoi = require('@escook/express-joi') // 导入验证表单数据中间件
const userHandler = require('../router_handler/user') // 导入处理函数
const { userSchema } = require('../schema/user')

// 注册
router.post('/reguser', expressJoi(userSchema), userHandler.reguser)

// 登录
router.post('/login', expressJoi(userSchema), userHandler.login)

module.exports = router
