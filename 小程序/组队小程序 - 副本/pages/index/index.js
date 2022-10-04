// pages/index/index.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    swiperList:[]
  },
  onLoad: function (options) {
      wx.request({ 
      url: 'https://wxapi.wuwuwu223.cn/pic',
      success: (result)=>{
        this.setData({
          swiperList:result.data.pictures
        }) 
      },
    });
  }
})