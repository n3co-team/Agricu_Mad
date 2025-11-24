set -e


CURRENT_BRANCH=$(git branch | grep "^\*" | cut -d" " -f2)

if [[ $1 == "lo" ]]
then
	git reset --hard origin/${CURRENT_BRANCH}
elif [[ $1 == "di" ]]
then
	git push --force-with-lease
fi

read -rp "Voullez vous pousser vers github votre nouveau modification ?"
read -p "Message de validation : " message
if [[ -z ${message} ]] 
then
	message=$(date +%D)
fi
	git add .
	find . -type f -name "agricu" -exec rm {} \;
	find . -type f -name "a.out" -exec rm {} \;
	git rm --cached $0
	git commit -m "${message}"
	git push origin ${CURRENT_BRANCH}
