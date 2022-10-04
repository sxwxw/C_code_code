const express = require('express')
const router = express.Router() // 创建路由对象
const expressJoi = require('@escook/express-joi')
const userInfoHandler = require('../router_handler/userinfo')
const { userInfoSchema } = require('../schema/userinfo')
const { updatePwdSchema } = require('../schema/user')

// 获取用户信息
router.get('/userinfo', userInfoHandler.getUserInfo)

// 更新用户信息
router.post('/updateUserInfo', expressJoi(userInfoSchema), userInfoHandler.updateUserInfo)

// 重置密码
router.post('/updatePwd', expressJoi(updatePwdSchema), userInfoHandler.updatePwd)

module.exports = router
