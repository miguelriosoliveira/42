ssh-keygen -t rsa -N '' -f ~/.ssh/id_rsa <<< y
eval "$(ssh-agent -s)"
touch ~/.ssh/config
echo "Host github.com
  AddKeysToAgent yes
  IdentityFile ~/.ssh/id_rsa" >> ~/.ssh/config
ssh-add ~/.ssh/id_rsa
cp ~/.ssh/id_rsa.pub id_rsa_pub

