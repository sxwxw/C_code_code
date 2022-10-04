// pages/index_02/index_02.js
Page({
  data: {
    num:0
  },
  // 输入框input事件的响应函数
  handinput(e){
    // console.log(e.detail.value);
    this.setData({
      num:e.detail.value
    })
  },
  headtap(e){
    const operation=e.currentTarget.dataset.operation
    this.setData({
      num:this.data.num + operation
    })
  }
})