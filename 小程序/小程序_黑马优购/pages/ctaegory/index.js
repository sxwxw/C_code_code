// 引入放送请求的方法
import {request } from '../../request/index.js';
import regeneratorRuntime from '../../lib/runtime/runtime';
Page({
  data: {
    // 左侧的菜单
    leftmeunlist:[],
    rightmeunlist:[],
    currenindex:0,
    scrolltop:0
  },
  onLoad: function (options) {
    // this.getCates();
    // 缓存数据
    // 1.判断本地数据
    const Cates = wx.getStorageSync("cast");
    if(!Cates)
    {
      this.getCates();
    }
    else {
      if(Date.now()-Cates.time>1000*10)
      {
        this.getCates();
      }
      else{
        this.cast =Cates.data;
        // 构造左侧大菜单数据
        let leftmeunlist = this.cast.map(v=>v.cat_name);
        let rightmeunlist = this.cast[0].children;
        this.setData({
          leftmeunlist,
          rightmeunlist
        })
      }
    }
  },
  // 接口的返回数据
  cast:[],
  // 获取分类数据
  async getCates(){
    // request({
    //   url:'/categories'
    // })
    // .then(reslut=>{
    //   this.cast=reslut.data.message;
    //   // 把接口数据存入到本地存储中
    //   wx.getStorageSync("cast",{time:Date.now(),data:this.cast})
    //   // 构造左侧大菜单数据
    //   let leftmeunlist = this.cast.map(v=>v.cat_name);
    //   let rightmeunlist = this.cast[0].children;
    //   this.setData({
    //     leftmeunlist,
    //     rightmeunlist
    //   })
      
    //   })
        // 使用es7的asyn await来发送请求
        const res=await request({url:'/categories'})
        this.cast=res;
        // 把接口数据存入到本地存储中
        wx.setStorageSync("cast",{time:Date.now(),data:this.cast})
        // 构造左侧大菜单数据
        let leftmeunlist = this.cast.map(v=>v.cat_name);
        let rightmeunlist = this.cast[0].children;
        this.setData({
          leftmeunlist,
          rightmeunlist
        })
  },
  // 左侧菜单的点击事件
  handleitemtap(e){
    const index =e.currentTarget.dataset.index;
    
    let rightmeunlist = this.cast[index].children;
      this.setData({
      currenindex:index,
      rightmeunlist,
      scrolltop:0
    })
  }
})