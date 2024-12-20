# Github登录的步骤
原因： 从2021年8月13日之后就不再支持用户名和密码的方式验证了，需要创建个人访问令牌(personal access token).
首先需要生成令牌：
1. 进入github官网，点击个人的头像，在弹窗中选择Settings->Developer settings(左侧页面拉到最下面)-> Personal access tokens-> Tokens(classic)->Generate new token->New personal access token (classic)
2. 将Expiration设置为：No expiration， Select scopes中选择所有的权限支持，点击“Generate token”
3. 页面更新后，生成一个 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 ，前面是绿色的对钩。NOTE：这个token后面看不到了，本次需要复制下来，但是不能泄露！！
4. 报错信息为：'https://github.com/Tommaker/UnityTestCProject.git， 只需要将生成的token@添加到github之前即可
5. 如果是现有的工程无法登录，则需要重选设置远端的url地址： git remote set-url origin  https://<your_token>@github.com/<USERNAME>/<REPO>.git
 如：git remote set-url origin https://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@github.com/Tommaker/UnityTestCProject.git
6. 若需要clone一个新工程，则之间使用 git clone https://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@github.com/Tommaker/UnityTestCProject.git
5. https://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@github.com/Tommaker/UnityTestCProject.git


# 重选设置远端git url的格式方法
git remote set-url origin  https://<your_token>@github.com/<USERNAME>/<REPO>.git
git remote set-url origin  https://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@github.com/nlp-greyfoss/typora_notes.git/


https://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@github.com/Tommaker/UnityTestCProject.git
