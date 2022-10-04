// components/macks/macks.js
Component({
  /**
   * 组件的属性列表
   */
  properties: {
    // 父组件给子组件传递数组选项
    areas: {
      type: Array,
      default: []
    },
    // 父组件控制子组件遮罩是否显示 默认为true
    showMack: {
      type: Boolean,
      default: false
    }
  },

  /**
   * 组件的初始数据
   */
  data: {
    areaAry: [], // 城市列表
    topItemId: 'demo0', // 选择城市 右侧的字母选择
    texts: '选择城市', // 选择后显示的文字
    // maskStart:false, // 遮罩是否显示
  },

  /**
   * 组件挂在执行钩子
   */
  lifetimes: {
    // 在组件实例进入页面节点树时执行
    attached: function () {
      this.setData({
        areaAry: this.data.areas, //这个地方 一会都做完 再给你讲怎么回事
      })
    }
  },

  /**
   * 组件的方法列表
   */
  methods: {
    // 点击字母跳转省份
    handClickText(e) {
      let topItemId = e.currentTarget.dataset.areaid; // 获取自定义属性 城市模块ID
      this.setData({
        topItemId
      })
    },

    // 选择城市 并隐藏遮罩
    handClickCity(e) {
      let cityText = e.currentTarget.dataset.city; // 获取自定义属性 城市名称
      this.setData({
        texts: cityText // 设置城市名称
      });
      this.triggerEvent('handClickCitpy', { mackStatus: false, cityText })
    },

    /**
     * 隐藏遮罩层
     */
    handClickHidden() {
      this.triggerEvent('handClickHidden', { mackStatus: false })
    }
  }
})