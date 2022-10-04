// pages/user/index.js
import { areaAry } from '../../utils/areas';
import { types } from '../../utils/types';
Page({
  data: {
    areaAry,
    showMack: false,
    cityText: '请选择',
    types,
    showTypesMack: false,
    typeText: '请选择',
    cityStatus: false
  },
  onLoad: function (options) {

  },

  /**
   * 点击显示城市选择
   */
  handClickArea() {
    this.setData({
      showMack: true
    })
  },
  /**
   * 获取被选择城市
   */
  handClickCitpy(e) {
    let { cityText, mackStatus } = e.detail;
    this.setData({
      showMack: mackStatus,
      cityText,
      cityStatus: true
    });
  },
  /**
   * 隐藏遮罩
   */
  handClickHidden(e) {
    let { mackStatus } = e.detail;
    this.setData({
      showMack: mackStatus
    });
  },
  //点击显示招生类别
  showCate() {
    this.setData({
      showTypesMack: true
    })
  },
  /**
   * 隐藏类别选择
   */
  handClickTypesHidden() {
    this.setData({
      showTypesMack: false
    })
  },

  /**
   * 设置类别
   * @param {*} e 对象参数
   */
  handClickTypes(e) {
    let { cityText, mackStatus } = e.detail;
    this.setData({
      showTypesMack: mackStatus,
      typeText: cityText
    });
  }
})