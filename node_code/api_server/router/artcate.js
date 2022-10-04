const express = require('express')
const router = express.Router() // 创建路由对象
const artcateHandle = require('../router_handler/artcate')
const expressJoi = require('@escook/express-joi') // 导入验证表单数据中间件
const { articleSchema, articleByIdSchema } = require('../schema/artcate')

// 获取文章分类
router.get('/cates', artcateHandle.getArticleCates)

// 根据id获取数据
router.get('/cates/:id', expressJoi(articleByIdSchema), artcateHandle.getArticleById)

// 新增文章分类
router.post('/addArticle', expressJoi(articleSchema), artcateHandle.addArticle)

// 更新文章分类
router.post('/updateArticle', artcateHandle.updateArticle)

module.exports = router
