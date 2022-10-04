// pages/demo/demo.js

Page({

  /**
   * 页面的初始数据
   */
  data: {},

  // 显示遮罩
  handShowMask() {
    // 打开遮罩 选择城市
    this.setData({
      maskStart: false
    })
  },
  
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {},

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    const query = wx.createSelectorQuery();
    query.select('#pie').fields({
      node: true,
      size: true
    }).exec((res) => {
      const canvas = res[0].node;
      const ctx = canvas.getContext('2d');
      const dpr = wx.getSystemInfoSync().pixelRatio;
      canvas.width = res[0].width * dpr;
      canvas.height = res[0].height * dpr;
      ctx.scale(dpr, dpr);
      ctx.beginPath()
      ctx.arc(res[0].width / 2, res[0].height / 2, res[0].width / 4, 0, 1.3 * Math.PI);
      ctx.arcTo(res[0].width / 2, res[0].height / 2, res[0].width / 2, res[0].height / 2, 0);
      ctx.fillStyle = 'red'
      ctx.fill();
      ctx.beginPath()
      ctx.arc(res[0].width / 2, res[0].height / 2, res[0].width / 4, 1.3 * Math.PI, 1.8 * Math.PI)
      ctx.arcTo(res[0].width / 2, res[0].height / 2, res[0].width / 2, res[0].height / 2, 0);
      ctx.fillStyle = 'blue'
      ctx.fill();
      ctx.beginPath()
      ctx.arc(res[0].width / 2, res[0].height / 2, res[0].width / 4, 1.8 * Math.PI, 2 * Math.PI)
      ctx.arcTo(res[0].width / 2, res[0].height / 2, res[0].width / 2, res[0].height / 2, 0);
      ctx.fillStyle = '#000000'
      ctx.fill();
      ctx.beginPath()
      ctx.arc(res[0].width / 2, res[0].height / 2, res[0].width / 5, 0, 2 * Math.PI)
      ctx.arcTo(res[0].width / 2, res[0].height / 2, res[0].width / 2, res[0].height / 2, 0);
      ctx.fillStyle = 'white'
      ctx.fill();
      ctx.beginPath()
    });
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})