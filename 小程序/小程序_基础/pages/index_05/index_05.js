// pages/index_05/index_06.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    tabs:[
      {
          id:0,
          name:"首页",
          isActive:true
      },
      {
          id:1,
          name:"原创",
          isActive:false
      },
      {
          id:2,
          name:"分类",
          isActive:false
      },
      {
          id:3,
          name:"关于",
          isActive:false
      },
    ]
  },
  // 自定义事件
  fszhanshu(e){
    const index = e.detail;
    let {tabs}=this.data;
    // console.log({tabs});
    // console.log(tabs);
    // v是每一个循环项相当于item
    tabs.forEach((v,i)=>i===index?v.isActive=true:v.isActive=false)
    this.setData({
        tabs
    })
  }

})