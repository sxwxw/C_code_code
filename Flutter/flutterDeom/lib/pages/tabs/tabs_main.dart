import 'package:flutter/material.dart';
import 'tabs_home.dart';
import 'tabs_info.dart';
import 'tabs_search.dart';

class Tabs extends StatefulWidget {
  final index;
  const Tabs({Key? key, this.index = 0}) : super(key: key);

  @override
  _TabsState createState() => _TabsState(index);
}

class _TabsState extends State<Tabs> {
  // int _currenIndex = 0;
  int _tabIndex = 0;
  _TabsState(index) {
    _tabIndex = index;
  }
  final List _tabsPages = [
    const home(),
    const search(),
    const info(),
  ];

  get drawer => null;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('页面跳转'),
      ),
      floatingActionButton: Container(
        height: 55,
        width: 55,
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(27),
          color: Colors.red,
        ),
        child: FloatingActionButton(
          child: Icon(
            Icons.add,
            size: 50,
          ),
          onPressed: () {
            setState(() {
              _tabIndex = 1;
            });
          },
          backgroundColor: _tabIndex == 1 ? Colors.red : Colors.yellow,
        ),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
      body: _tabsPages[_tabIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _tabIndex,
        onTap: (int index) {
          setState(() {
            _tabIndex = index;
          });
        },
        fixedColor: Colors.pink,
        type: BottomNavigationBarType.fixed,
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.home),
            label: "首页",
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.search),
            label: "首页",
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.info),
            label: "首页",
          ),
        ],
      ),
      // 左侧侧边栏
      drawer: Drawer(
        child: Column(
          children: <Widget>[
            Row(
              children: const [
                Expanded(
                  // child: DrawerHeader(
                  //   child: Text(''),
                  //   decoration: BoxDecoration(
                  //     color: Colors.red,
                  //     image: DecorationImage(
                  //       image: AssetImage('images/2.jpg'),
                  //       fit: BoxFit.cover,
                  //     ),
                  //   ),
                  // ),
                  child: UserAccountsDrawerHeader(
                    currentAccountPicture: CircleAvatar(
                      backgroundImage: AssetImage('images/2.jpg'),
                    ),
                    accountName: Text(
                      "大地老师",
                      style: TextStyle(fontSize: 18),
                    ),
                    accountEmail: Text(
                      'you.com',
                      style: TextStyle(fontSize: 15),
                    ),
                  ),
                )
              ],
            ),
            ListTile(
              leading: const CircleAvatar(
                child: Icon(Icons.search),
              ),
              title: Text('用户中心'),
              onTap: () {
                Navigator.of(context).pop(); // 隐藏侧边栏
                Navigator.pushNamed(context, '/user');
              },
            ),
            Divider()
          ],
        ),
      ),
      // 右侧侧边栏
      endDrawer: const Drawer(
        child: Text('你好'),
      ),
    );
  }
}
