import 'package:flutter/material.dart';

void main() {
  runApp(myApp());
}

class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('列表')),
        body: HomeContent(),
      ),
    );
  }
}

// 无状态组件
// class HomeContent extends StatelessWidget {
//   int num = 0;
//   @override
//   Widget build(BuildContext context) {
//     return Column(
//       children: [
//         Text('$num'),
//         ElevatedButton(
//           onPressed: () {
//             num++;
//             print(num);
//           },
//           child: Text('按钮'),
//         )
//       ],
//     );
//   }
// }
// 有状态组件
class HomeContent extends StatefulWidget {
  const HomeContent({Key? key}) : super(key: key);

  @override
  _HomeContentState createState() => _HomeContentState();
}

class _HomeContentState extends State<HomeContent> {
  int num = 0;
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        children: [
          Chip(
            label: Text("$num"),
          ),
          ElevatedButton(
            onPressed: () {
              setState(() {
                num++;
              });
            },
            child: Text("按钮"),
          )
        ],
      ),
    );
  }
}
