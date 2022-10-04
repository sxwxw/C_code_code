const gulp = require('gulp')
// gulp.task 建立gulp任务
// gulp.src 获取处理文件
// gulp.dest 输出文件
gulp.task('first', () => {
  gulp.src('./src/css/index.css').pipe(gulp.dest('./dist/css'))
})

// 压缩html文件
const htmlmin = require('gulp-htmlmin')
gulp.task('htmlmin', () => {
  gulp
    .src('./src/*.html')
    .pipe(htmlmin({ collapseWhitespace: true }))
    .pipe(gulp.dest('./dist/css'))
})
