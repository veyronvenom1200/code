from django.shortcuts import render

# Create your views here.
from projects.models import Project

def project_index(request):
	projects = Project.objects.all()
	context = {
		'projects': projects
	}
	return render(request, "project_index.html", context)

def project_detail(request, pk): #pk = primary key
	project = Project.objects.get(pk=pk)
	context = {
		'project': project
	}
	return render(request, "project_detail.html", context)
