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

exports.updatePwdSchema = {
  body: {
    oldPwd: password,
    // ref 表示新密码和旧密码必须一致
    // not 表示新密码不能等于旧密码
    // concat 合并password和newPwd这条密码的验证规则
    newPwd: joi.not(joi.ref('oldPwd')).concat(password)
  }
}
