// 导入模块
const joi = require('joi')

// 定义验证规则
const name = joi.string().required()
const alias = joi.string().alphanum().required()
const id = joi.number().integer()

// 定义数据的规则对象
exports.articleSchema = {
  body: {
    name,
    alias
  }
}

exports.articleByIdSchema = {
  params: {
    id
  }
}
