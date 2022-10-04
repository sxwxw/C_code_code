// app.js
App({
  // 应用第一次启动就会触发的事件
  onLaunch() {
    // 展示本地存储能力
    const logs = wx.getStorageSync('logs') || []
    logs.unshift(Date.now())
    wx.setStorageSync('logs', logs)

    // 登录
    wx.login({
      success: res => {
        // 发送 res.code 到后台换取 openId, sessionKey, unionId
      }
    })
  },
  // 组件所在的页面被展示时执行
  onShow(){
    
  },
  // 组件所在的页面被隐藏时执行
  onHide(){

  },
  // 代码报错
  onError(){

  },
  // 第一次启动是页面找不到第一个入口页面时触发
  onPageNotFound(){
    
  },
  globalData: {
    userInfo: null
  }
})
