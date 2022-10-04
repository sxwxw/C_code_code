// 导入模块
const joi = require('joi')

// 定义验证规则
const id = joi.number().integer().min(1).required()
const nickname = joi.string().required()
const email = joi.string().email().required()

// 定义数据的规则对象
exports.userInfoSchema = {
  body: {
    id,
    nickname,
    email
  }
}
