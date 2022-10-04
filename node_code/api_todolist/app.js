const express = require('express')
const cors = require('cors')

const app = express()

const userRouter = require('./router/todoList')
const errorHandle = require('./middleware/error')

app.use(express.json())
app.use(cors())

app.use('/api', userRouter)

app.use(errorHandle())

app.listen(8080, () => {
  console.log('server is sucess http://127.0.0.1:8080')
})
