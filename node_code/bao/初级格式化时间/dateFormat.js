// 定义格式化时间的方法
function dateFormat(dtStr) {
  // 创建Date对象
  const dt = new Date(dtStr)
  const y = dt.getFullYear()
  const m = addZero(dt.getMonth() + 1)
  const d = addZero(dt.getDate())

  const hh = addZero(dt.getHours())
  const mm = addZero(dt.getMinutes())
  const ss = addZero(dt.getSeconds())

  return `${y}-${m}-${d} ${hh}:${mm}:${ss}`
}

// 补0
function addZero(n) {
  return n > 9 ? n : '0' + n
}

module.exports = {
  dateFormat
}
