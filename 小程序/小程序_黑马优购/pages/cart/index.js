// pages/cart/index.js
import {getSetting,chooseAddress,openSetting} from "../../utils/asyncwx.js"
import regeneratorRuntime from '../../lib/runtime/runtime';

Page({
  data: {
    address:{},
    cart:[],
    allchecked:false,
    totalprice:0,
    totalnum:0
  },
  onShow(){
    const address = wx.getStorageSync('address');
    const cart = wx.getStorageSync('cart')||[];
    this.setcart(cart);
    this.setData({
      address
    })
  },
  onLoad: function (options) {

  },
  async handleaddress(){
    try{
      const res1 = await getSetting();
      const scopeAddress = res1.authSetting["scope.address"];
      if(scopeAddress===false){
        await openSetting();
      }else{
      } 
      // 存入缓存中
      const address = await chooseAddress();
      wx.setStorageSync('address', address)
    }catch(error){
      console.log(error);
    }
  },
  // 选中状态
  handeitemchangce(e){
    // console.log(e);
    const goods_id = e.currentTarget.dataset.id;
    // console.log(goods_id);
    let {cart} = this.data;
    let index = cart.findIndex(v=>v.goods_id===goods_id);
    cart[index].checked=!cart[index].checked;
    this.setcart(cart);
  },
  //常用api
   setcart(cart){
    wx.setStorageSync('cart',cart);
    let totalprice = 0;
    let totalnum = 0;
    let allchecked = true;
    
    cart.forEach(v => {
      if(v.checked)
      {
        totalprice+=v.goods_price*v.num;
        totalnum+=v.num;
      }else{
        allchecked=false;
      }
      
    });
    allchecked = cart.length!=0?allchecked:false;
    this.setData({
      cart,totalprice,totalnum,allchecked
    })
   },
  //  全选和反选
  handeallchecked(){
    let {cart,allchecked}=this.data;
    allchecked=!allchecked;
    cart.forEach(v=>v.checked=allchecked);
    this.setcart(cart);

  },
  // 加减按键
  handleitemnumedit(e){
    // console.log(e);
    const {operation,id}=e.currentTarget.dataset;
    // console.log({operation,id});
    let {cart} = this.data;
    const index = cart.findIndex(v=>v.goods_id===id);
    if(cart[index].num===1&&operation===-1)
    {
      wx.showModal({
        title: '提示',
        content: '您是否要删除',
        success: (result) => {
          if(result.confirm){
            cart.splice(index,1);
            this.setcart(cart);
          }else if(result.cancel)
          {
            console.log("用户点击取消");
          }
        }
      });
    }else{
      cart[index].num+=operation;
      this.setcart(cart);
    }
   
  },
  handzhifu(){
    wx.navigateTo({
      url: '../../pages/pay/index'
    })
  }
})