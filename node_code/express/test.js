// express基于http模块封装
// 可创建web网站服务器和API接口服务器
// 在express中，路由就是客户端和服务器之间的映射关系

// 导入express
const express = require('express')

// 创建服务器
const app = express()

// 挂载路由 监听客户端请求
const useRouter = require('./router.js')

// 定义中间件
const mv = function (rq, res, next) {
  console.log('中间件')
  // next()把流转函数转交给下一个中间件或路由
  next()
}

// app.use() 注册全局中间件 绑定在app上的称为应用级别的中间件
// 在路由之前注册中间件
app.use(mv)
// express.static() 托管静态资源
app.use(express.static('./clock'))
// express.json() 解析json格式请求数据
app.use(express.json())
// express.urlencoded() 解析url-encoded格式请求数据
app.use(express.urlencoded())
// 注册路由模块
app.use('/api', useRouter)

// 启动服务器
app.listen(80, () => {
  console.log('启动成功 http://127.0.0.1')
})
