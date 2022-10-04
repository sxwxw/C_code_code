const db = require('../db/index')

exports.getArticleCates = (req, res) => {
  const articleSql = `select * from article_cate order by id asc`
  db.query(articleSql, (err, result) => {
    if (err) {
      return res.cc(err)
    }
    res.send({
      status: 200,
      msg: '获取成功',
      data: result
    })
  })
}

exports.getArticleById = (req, res) => {
  const ArticleByIdSql = `select * from article_cate where id=?`
  db.query(ArticleByIdSql, req.params.id, (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.length != 1) {
      return res.cc('获取分类数据失败')
    }
    res.send({
      status: 200,
      msg: '获取文章分类数据成功',
      data: result[0]
    })
  })
}

exports.addArticle = (req, res) => {
  const sql = `select * from article_cate where name=? or alias=?`
  db.query(sql, [req.body.name, req.body.alias], (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.length === 2) {
      return res.cc('分类名称与别名被占用，请重新更换')
    }
    if (result.length === 1 && result[0].name === req.body.name && result[0].alias === req.body.alias) {
      return res.cc('分类名称与别名被占用，请重新更换')
    }
    if (result.length === 1 && result[0].name === req.body.name) {
      return res.cc('分类名称被占用，请重新更换')
    }
    if (result.length === 1 && result[0].alias === req.body.alias) {
      return res.cc('别名被占用，请重新更换')
    }
    const addArticle = `insert into article_cate set ?`
    db.query(addArticle, req.body, (err, result) => {
      if (err) {
        return res.cc(err)
      }
      if (result.affectedRows != 1) {
        return res.cc('新增文章失败')
      }
      res.cc('新增文章成功', 200)
    })
  })
}

exports.updateArticle = (req, res) => {
  const updateSql = `update article_cate set ? where id=?`
  db.query(updateSql, [req.body, req.body.id], (err, result) => {
    if (err) {
      return res.cc(err)
    }
    if (result.affectedRows != 1) {
      return res.cc('修改分类数据失败')
    }
    const sql = `select * from article_cate where id=?`
    db.query(sql, req.body.id, (err, result) => {
      res.send({
        status: 200,
        msg: '修改文章分类数据成功',
        data: result[0]
      })
    })
  })
}
