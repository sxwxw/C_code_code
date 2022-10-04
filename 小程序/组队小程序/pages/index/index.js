import {request} from '../../request/promise.js'
// pages/index/index.js
Page({
  data: {
    swiperList:[]
  },
  onLoad: function (options) {
    this.getlun();
  },
  // 轮播图封装
  getlun(){
    request({
      url: '/pic'
    }).then(res=>{
      this.setData({
        swiperList:res.data.pictures
      }) 
    }).catch(err=>{
      console.log(err);
    })
  },
  // 阻止父子navigator冒泡
  funNull(){
    console.log("hhhh");
  }
})