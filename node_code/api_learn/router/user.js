const express = require('express')
const router = express.Router()
// 导入基本数据验证中间件
const expressJoi = require('@escook/express-joi')
// 导入验证规则
const { userSchema } = require('../schema/user')
// 导入处理函数
const userHandle = require('../controller/user')

// 登录
router.post('/login', expressJoi(userSchema), userHandle.login)

// 注册
router.post('/reguser', expressJoi(userSchema), userHandle.reguser)

module.exports = router
