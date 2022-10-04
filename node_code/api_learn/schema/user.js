// 导入模块
const joi = require('joi')

// 定义用户名和密码的验证规则
const username = joi.string().alphanum().min(3).max(12).required()
const password = joi
  .string()
  .pattern(/^[\S]{6,15}$/)
  .required()

// 定义注册和登陆表单数据的规则对象
exports.userSchema = {
  body: {
    username,
    password
  }
}
