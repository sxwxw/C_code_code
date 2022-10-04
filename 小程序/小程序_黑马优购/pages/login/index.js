// pages/login/index.js
Page({
  handleuserinfo(e){
    // console.log(e);
    const {userInfo} = e.detail;
    wx.setStorageSync('userinfo', userInfo);
    // wx.navigateBack({
    //   detal:1
    // })
  }
})