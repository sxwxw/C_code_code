// 引入放送请求的方法
import {request } from '../../request/index.js';
import regeneratorRuntime from '../../lib/runtime/runtime';
Page({
  data: {
    goodsobj:{}
  },
  goodsinfo:{},
  onLoad: function (options) {
    const {goods_id}=options
    // console.log(goods_id);
    this.getgoodsdetail(goods_id);
    // console.log(this.data.cart);
  },
  // 获取商品详情
  async getgoodsdetail(goods_id){
    const goodsobj = await request({url:"/goods/detail",data:{goods_id}});
    this.goodsinfo=goodsobj;
    // console.log(this.goodsinfo);
    // console.log(res);
    this.setData({
      goodsobj:{
        goods_name:goodsobj.goods_name,
        goods_price:goodsobj.goods_price,
        goods_introduce:goodsobj.goods_introduce,
        pics:goodsobj.pics
      }
    })
  },
  // 轮播图放大预览点击事件
  handleprevewimage(e){
    // console.log("hhhh");
    console.log(e);
    const urls = this.goodsinfo.pics.map(v=>v.pics_mid);
    const {url} = e.currentTarget.dataset;
    console.log(urls);
    wx.previewImage({
      current:url,
      urls: urls,
      
    });
  },
  handlecartadd(){
    // console.log(cart);
    // 将 data 存储在本地缓存中指定的 key 中，会覆盖掉原来该 key 对应的内容，这是一个同步接口。
    let cart = wx.getStorageSync('cart')||[];
    let index = cart.findIndex(v=>v.goods_id===this.goodsinfo.goods_id)
    if(index===-1)
    {
      this.goodsinfo.num=1;
      this.goodsinfo.checked=true;
      cart.push(this.goodsinfo);
    }
    else{
      cart[index].num++;
    }
    // 从本地缓存中同步获取指定 key 对应的内容。
    wx.setStorageSync('cart', cart);
    wx.showToast({
      title: '加入成功',
      icon: 'success',
      mask:true
    });
  }
})
// wx.setStorageSync(KEY,DATA)

// 将 data 存储在本地缓存中指定的 key 中，会覆盖掉原来该 key 对应的内容，这是一个同步接口。

// wx.getStorageSync(KEY)

// 从本地缓存中同步获取指定 key 对应的内容。