from django.shortcuts import render
from .models import Todo
from django.utils import timezone
from .forms import TodoForm
from django.contrib.auth.models import User
from django.shortcuts import redirect

def task_list(request):
    todo=Todo.objects.filter(created_date__lte=timezone.now()).order_by('to_be_date')
    return render(request, 'todolist/task_list.html',{'todo':todo})

def add_todo(request):
    if request.method=='GET':
        return render(request, 'todolist/add_list.html', {'form':TodoForm()})
    else:
        form=TodoForm(request.POST)
        tod=form.save(commit=False)
        tod.user=request.user

        tod.save()
        todos=Todo.objects.filter(created_date__lte=timezone.now()).order_by('to_be_date')
        return render(request, 'todolist/task_list.html',{'todo':todos})

def delete(request, id):
    Todo.objects.filter(id=id).delete()
    return redirect(task_list)

def update(request, id):
    Todo.objects.filter(id=id).update(done_status=True)
    return redirect(task_list)

def update_not_completed(request, id):
    Todo.objects.filter(id=id).update(done_status=False)
    return redirect(task_list)

def edit(request, id):
    todo=Todo.objects.filter(id=id)
    if request.method == 'POST':
        print(request.POST.get('task_title') )
        title_txt=request.POST['task_title'] 
        description_txt=request.POST['task_description'] 
        completion_date=request.POST['to_be_date']
        obj=Todo.objects.get(id=id)
        obj.task_title=title_txt
        obj.task_description=description_txt
        obj.to_be_date=completion_date
        obj.save()
        return redirect(task_list)
    return render(request, 'todolist/update.html', {'todos':todo})


# def update_in_db(request, id):
#     print("Hiiiiiiiii")
#     if request.method == 'POST':
#         print(request.POST.get['task_title'] )
#         title_txt=request.POST['task_title'] 
#         description_txt=request.POST['task_description'] 
#         completion_date=request.POST['to_be_date']
#         obj=Todo.objects.get(id=id)
#         obj.task_title=title_txt
#         obj.task_description=description_txt
#         obj.to_be_date=completion_date
#         obj.save()
#         return redirect(task_list)
#     else:
#         one_item=Todo.objects.get(id=id)
#         return render(request, 'todolist/update.html', {'one':one_item })
        



