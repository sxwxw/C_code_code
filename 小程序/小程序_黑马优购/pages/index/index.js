// 引入放送请求的方法
import {request } from '../../request/index.js'
Page({

  /**
   * 页面的初始数据
   */
  data: {
    swiperList:[],
    cateslist:[],
    floorlist:[]
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    // 发送异步请求获取轮播图数据 通过promise优化代码
    //   wx.request({ 
    //   url: 'https://api-hmugo-web.itheima.net/api/public/v1/home/swiperdata',
    //   success: (result)=>{
    //     this.setData({
    //       swiperList:result.data.message
    //     }) 
    //   },
    // });
    this.getswiperlist();
    this.getcateslist();
    this.getfloorlist()
  },
  // 获取轮播图数据
  getswiperlist(){
    request({url: '/home/swiperdata'})
    .then(result=>{
      this.setData({
              swiperList:result
      }) 
    })
  },

  // 获取分类导航数据
  getcateslist(){
    request({url: '/home/catitems'})
    .then(result=>{
      this.setData({
        cateslist:result
      }) 
    })
  },

  // 获取楼层数据
  getfloorlist(){
    request({url: '/home/floordata'})
    .then(result=>{
      this.setData({
        floorlist:result
      }) 
    })
  }
})